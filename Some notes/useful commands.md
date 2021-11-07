useful commands
***
**file**
```
-> file XXX
#get the XXX file type 

-> % file zshrc.sh 
zshrc.sh: UTF-8 Unicode text

```
**free**
```
-> % free -g
              total        used        free      shared  buff/cache   available
Mem:             11           1           8           0           2           9
Swap:            11           0          11

-> % free -m
              total        used        free      shared  buff/cache   available
Mem:          11911        1393        8369         221        2149        9915
Swap:         11443           0       11443

-> % free  
              total        used        free      shared  buff/cache   available
Mem:       12197788     1426356     8571824      225928     2199608    10154416
Swap:      11718652           0    11718652

```

**size**
```
-> % size ns3
   text	   data	    bss	    dec	   	 hex	filename
16969639	 357923	 147312	17474874	10aa53a	ns3
#show the size of file in detail

```

**clear file content** 
```
-> % >XXX.log
#make the xxx.log empty 
```

**Watching big log**
```
-> % cat XXX.log | more
#watching the log per page
```
**listing all kernel modules**
```
-> % lsmod
Module                  Size  Used by
nfnetlink_queue         8111  0 
nfnetlink_log           8686  0 
nfnetlink               4200  2 nfnetlink_queue,nfnetlink_log
bluetooth              97799  0 
rfkill                 19255  1 bluetooth
tcp_diag                1041  0 
inet_diag               9430  1 tcp_diag
ip6t_REJECT             4372  2 
nf_conntrack_ipv6       7985  2 
nf_defrag_ipv6         26468  1 nf_conntrack_ipv6
xt_state                1492  2 
nf_conntrack           79537  2 nf_conntrack_ipv6,xt_state
ip6table_filter         2889  1 
ip6_tables             18796  1 ip6table_filter
ipv6                  336368  37 ip6t_REJECT,nf_conntrack_ipv6,nf_defrag_ipv6
tcp_htcp                3481  813 
joydev                 10480  0 
virtio_balloon          4798  0 
virtio_net             21970  0 
i2c_piix4              11232  0 
i2c_core               29132  1 i2c_piix4
ext4                  381065  2 
jbd2                   93284  1 ext4
mbcache                 8193  1 ext4
virtio_blk              7132  4 
virtio_pci              7512  0 
virtio_ring             8891  4 virtio_balloon,virtio_net,virtio_blk,virtio_pci
virtio                  5639  4 virtio_balloon,virtio_net,virtio_blk,virtio_pci
pata_acpi               3701  0 
ata_generic             3837  0 
ata_piix               24409  0 
dm_mirror              14864  0 
dm_region_hash         12085  1 dm_mirror
dm_log                  9930  2 dm_mirror,dm_region_hash
dm_mod                102467  2 dm_mirror,dm_log

```

**timezone**
```
-> % timedatectl
               Local time: Thu 2021-11-04 01:01:07 CST
           Universal time: Wed 2021-11-03 17:01:07 UTC
                 RTC time: Wed 2021-11-03 17:01:07    
                Time zone: Asia/Shanghai (CST, +0800) 
System clock synchronized: yes                        
              NTP service: active                     
          RTC in local TZ: no 

-> % timedatectl set-timezone your_time_zone
#set timezone

-> % timedatectl list-timezones
#list available timezones
```

**dmesg**
```
#show kernel buffer
-> % dmesg | head -100
[    0.000000] Linux version 5.8.0-59-generic (buildd@lcy01-amd64-022) (gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0, GNU ld (GNU Binutils for Ubuntu) 2.34) #66~20.04.1-Ubuntu SMP Thu Jun 17 11:14:10 UTC 2021 (Ubuntu 5.8.0-59.66~20.04.1-generic 5.8.18)
[    0.000000] Command line: BOOT_IMAGE=/boot/vmlinuz-5.8.0-59-generic root=UUID=09009c3f-ab61-4884-af8a-ca8671b874bb ro find_preseed=/preseed.cfg auto noprompt priority=critical locale=en_US quiet
[    0.000000] KERNEL supported cpus:
[    0.000000]   Intel GenuineIntel
[    0.000000]   AMD AuthenticAMD
[    0.000000]   Hygon HygonGenuine
[    0.000000]   Centaur CentaurHauls
[    0.000000]   zhaoxin   Shanghai  
[    0.000000] Disabled fast string operations
[    0.000000] x86/fpu: Supporting XSAVE feature 0x001: 'x87 floating point registers'
[    0.000000] x86/fpu: Supporting XSAVE feature 0x002: 'SSE registers'
[    0.000000] x86/fpu: Supporting XSAVE feature 0x004: 'AVX registers'
[    0.000000] x86/fpu: Supporting XSAVE feature 0x008: 'MPX bounds registers'
[    0.000000] x86/fpu: Supporting XSAVE feature 0x010: 'MPX CSR'
[    0.000000] x86/fpu: xstate_offset[2]:  576, xstate_sizes[2]:  256
[    0.000000] x86/fpu: xstate_offset[3]:  832, xstate_sizes[3]:   64
[    0.000000] x86/fpu: xstate_offset[4]:  896, xstate_sizes[4]:   64
[    0.000000] x86/fpu: Enabled xstate features 0x1f, context size is 960 bytes, using 'compacted' format.
[    0.000000] BIOS-provided physical RAM map:
```

**pstree**
```
-> % pstree
systemd─┬─ModemManager───2*[{ModemManager}]
        ├─NetworkManager───2*[{NetworkManager}]
        ├─VGAuthService
        ├─accounts-daemon───2*[{accounts-daemon}]
        ├─acpid
        ├─avahi-daemon───avahi-daemon
        ├─bluetoothd
        ├─colord───2*[{colord}]
        ├─cron
        ├─cups-browsed───2*[{cups-browsed}]
        ├─cupsd───dbus
        ├─dbus-daemon
        ├─gdm3─┬─gdm-session-wor─┬─gdm-x-session─┬─Xorg───{Xorg}
        │      │                 │               ├─gnome-session-b─┬─ssh-agent
        │      │                 │               │                 └─2*[{gnome-session-b}]
        │      │                 │               └─2*[{gdm-x-session}]
        │      │                 └─2*[{gdm-session-wor}]
        │      └─2*[{gdm3}]
        ├─gnome-keyring-d───3*[{gnome-keyring-d}]
        ├─2*[kerneloops]
        ├─mysqld───36*[{mysqld}]
        ├─networkd-dispat
        ├─polkitd───2*[{polkitd}]
        ├─rsyslogd───3*[{rsyslogd}]
        ├─rtkit-daemon───2*[{rtkit-daemon}]
        ├─snapd───7*[{snapd}]
        ├─switcheroo-cont───2*[{switcheroo-cont}]
        ├─systemd─┬─(sd-pam)
        │         ├─at-spi-bus-laun─┬─dbus-daemon
        │         │                 └─3*[{at-spi-bus-laun}]
        │         ├─at-spi2-registr───2*[{at-spi2-registr}]
        │         ├─dbus-daemon
        │         ├─dconf-service───2*[{dconf-service}]
        │         ├─evinced───2*[{evinced}]
        │         ├─evolution-addre───5*[{evolution-addre}]
        │         ├─evolution-calen───8*[{evolution-calen}]
        │         ├─evolution-sourc───3*[{evolution-sourc}]
        │         ├─gjs───4*[{gjs}]
        │         ├─gnome-session-b─┬─evolution-alarm───5*[{evolution-alarm}]
        │         │                 ├─gsd-disk-utilit───2*[{gsd-disk-utilit}]
        │         │                 ├─update-notifier───3*[{update-notifier}]
        │         │                 └─3*[{gnome-session-b}]
        │         ├─gnome-session-c───{gnome-session-c}
        │         ├─gnome-shell─┬─ibus-daemon─┬─ibus-engine-sim───2*[{ibus-engine-sim}]
        │         │             │             ├─ibus-extension-───3*[{ibus-extension-}]
        │         │             │             ├─ibus-memconf───2*[{ibus-memconf}]
        │         │             │             └─2*[{ibus-daemon}]
        │         │             └─6*[{gnome-shell}]
        │         ├─gnome-shell-cal───5*[{gnome-shell-cal}]
        │         ├─goa-daemon───3*[{goa-daemon}]
        │         ├─goa-identity-se───2*[{goa-identity-se}]
        │         ├─gsd-a11y-settin───3*[{gsd-a11y-settin}]
        │         ├─gsd-color───3*[{gsd-color}]
        │         ├─gsd-datetime───3*[{gsd-datetime}]
        │         ├─gsd-housekeepin───3*[{gsd-housekeepin}]
        │         ├─gsd-keyboard───3*[{gsd-keyboard}]
        │         ├─gsd-media-keys───3*[{gsd-media-keys}]
        │         ├─gsd-power───3*[{gsd-power}]
        │         ├─gsd-print-notif───2*[{gsd-print-notif}]
        │         ├─gsd-printer───2*[{gsd-printer}]
        │         ├─gsd-rfkill───2*[{gsd-rfkill}]
        │         ├─gsd-screensaver───2*[{gsd-screensaver}]
        │         ├─gsd-sharing───3*[{gsd-sharing}]
        │         ├─gsd-smartcard───4*[{gsd-smartcard}]
        │         ├─gsd-sound───3*[{gsd-sound}]
        │         ├─gsd-usb-protect───3*[{gsd-usb-protect}]
        │         ├─gsd-wacom───2*[{gsd-wacom}]
        │         ├─gsd-wwan───3*[{gsd-wwan}]
        │         ├─gsd-xsettings───3*[{gsd-xsettings}]
        │         ├─gvfs-afc-volume───3*[{gvfs-afc-volume}]
        │         ├─gvfs-goa-volume───2*[{gvfs-goa-volume}]
        │         ├─gvfs-gphoto2-vo───2*[{gvfs-gphoto2-vo}]
        │         ├─gvfs-mtp-volume───2*[{gvfs-mtp-volume}]
        │         ├─gvfs-udisks2-vo───3*[{gvfs-udisks2-vo}]
        │         ├─gvfsd─┬─gvfsd-trash───2*[{gvfsd-trash}]
        │         │       └─2*[{gvfsd}]
        │         ├─gvfsd-fuse───5*[{gvfsd-fuse}]
        │         ├─gvfsd-metadata───2*[{gvfsd-metadata}]
        │         ├─ibus-portal───2*[{ibus-portal}]
        │         ├─ibus-x11───2*[{ibus-x11}]
        │         ├─pulseaudio───3*[{pulseaudio}]
        │         ├─tracker-miner-f───4*[{tracker-miner-f}]
        │         ├─vmtoolsd───{vmtoolsd}
        │         ├─x-terminal-emul─┬─zsh───gedit───4*[{gedit}]
        │         │                 ├─zsh───evince───6*[{evince}]
        │         │                 ├─zsh───pstree
        │         │                 └─4*[{x-terminal-emul}]
        │         └─xdg-permission-───2*[{xdg-permission-}]
        ├─systemd-journal
        ├─systemd-logind
        ├─systemd-resolve
        ├─systemd-timesyn───{systemd-timesyn}
        ├─systemd-udevd
        ├─udisksd───4*[{udisksd}]
        ├─unattended-upgr───{unattended-upgr}
        ├─upowerd───2*[{upowerd}]
        ├─vmtoolsd───{vmtoolsd}
        ├─vmware-vmblock-───2*[{vmware-vmblock-}]
        ├─whoopsie───2*[{whoopsie}]
        └─wpa_supplicant

```


