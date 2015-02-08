#!/usr/bin/env ruby
#
# LightWave RF Protocol documented here:
# https://wiki.somakeit.org.uk/wiki/LightwaveRF_RF_Protocol
#

NIBBLES = [0xF6,0xEE,0xED,0xEB,0xDE,0xDD,0xDB,0xBE,0xBD,0xBB,0xB7,0x7E,0x7D,0x7B,0x77,0x6F];

mapping = {
  '0xC2D0' => 'C0 F0 F3 18 90',
  '0xC2D0' => 'C0 F0 F3 18 90',
  '0xC038' => '82 F2 F3 18 90',
  '0xC084' => '00 01 F3 18 90',
  '0xC044' => '00 00 F3 18 90',
  '0xC0C4' => '00 11 F3 18 90',
  '0xC024' => '00 10 F3 18 90',
  '0xC0A4' => '00 21 F3 18 90',
  '0xC064' => '00 20 F3 18 90',
  '0xC0E4' => '00 31 F3 18 90',
  '0xC014' => '00 30 F3 18 90',
}

def lwrf_encode(bytes)
  raw_bytes = []
  bytes.each do |byte|
    raw_bytes << NIBBLES[ (byte >> 4) & 0xF ]
    raw_bytes << NIBBLES[ (byte >> 0) & 0xF ]
  end
  return raw_bytes.map{|b| sprintf("\\x%X", b)}.join
end

mapping.each_pair do |ir, lwrf|
  raw_bytes = lwrf_encode(lwrf.split.map{|str| str.hex})

  puts "case #{ir}:"
  puts "    lw_send((byte*)\"#{raw_bytes}\");"
  puts "break;"
end
