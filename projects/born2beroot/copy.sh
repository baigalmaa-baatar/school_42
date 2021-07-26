#!/bin/bash
echo -e "#Architecture:\t"`hostnamectl | grep "Operating System" | cut -d ' ' -f5-` | `awk -F':' '/^model name/ {print $2}' /proc/cpuinfo | uniq | sed -e 's/^[ \t]*//'` | `arch` | `uname -r`
echo -e "#CPU physical:\t" `cat /proc/cpuinfo | grep processor | wc -l`
echo -e "#vCPU :\t" `cat /proc/cpuinfo | grep processor | wc -l`
echo -e "#Memory usage :\t"
echo -e "#Disk usage :\t"`df -Ph | sed s/%//g | awk '{ if($5 > 80) print $0;}'`
echo -e "CPU load:\t" `cat /proc/stat | awk '/cpu/{printf("%.2f%\n"), ($2+$4)*100/($2+$4+$5)}' |  awk '{print $0}' | head -1`
echo -e "Last boot:\t" 
echo -e "LVM use :\t" 
echo -e "User log:\t" `w | cut -d ' ' -f1 | grep -v USER | xargs -n1`
echo -e "Network IP :\t" 
echo -e "Sudo :\t" 
echo ""
