#! /usr/bin/python

import re
import sys

def main(fil):
    content = open(fil, 'r').read()
    hostlist = re.split(r'SVSA\s+.*', content)[1:]
    print('_' * 40)
    for host in hostlist:
        hst, _, partition = re.findall(r'vhost.*',host)[0].split()
        partition = str(int(partition, 16))
        devices_vtd = zip(re.findall(r'VTD\s+(.*)',host),
                          re.findall(r'Backing device\s+(.*)', host))
        #print(devices_vtd)
        for device in devices_vtd:
            print(" | ".join([hst, device[0], device[1], partition]))

if __name__ == '__main__':
    assert(len(sys.argv) == 2)
    main(sys.argv[1])
