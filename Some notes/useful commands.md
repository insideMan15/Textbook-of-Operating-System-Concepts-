useful commands
***
file
```
-> file XXX
#get the XXX file type 

-> % file zshrc.sh 
zshrc.sh: UTF-8 Unicode text

```
free
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

size
```
-> % size ns3
   text	   data	    bss	    dec	   	 hex	filename
16969639	 357923	 147312	17474874	10aa53a	ns3
#show the size of file in detail

```

timezone
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
