#!/bin/bash

echo -e "#Architecture:\t" `hostnamectl | grep "Operating System" | cut -d ' ' -f5- ` `awk -F':' '/^model name/ {print $2}' /proc/cpuinfo | uniq | sed -e 's/^[ \t]*//'` `arch` `uname -r`
echo -e "#CPU physical:\t" `cat /proc/cpuinfo | grep processor | wc -l`
echo -e "#vCPU :\t" `cat /proc/cpuinfo | grep processor | wc -l`
free -m | awk 'NR==2{printf "#Memory Usage: %s/%sMB (%.2f%%)\n", $3,$2,$3*100/$2 }'
df -h | awk '$NF=="/"{printf "#Disk Usage: %d/%dGB (%s)\n", $3,$2,$5}'
top -bn1 | grep load | awk '{printf "#CPU Load: %.2f\n", $(NF-2)}'
echo -e "#Last boot:\t" `who -b | awk '{print $3" "$4" "$5}'`
echo -e "#LVM use :\t"
echo -e "#User log:\t" `w | cut -d ' ' -f1 | grep -v USER | xargs -n1`
echo -e "#Network IP :\t"
echo -e "#Sudo :\t"

sudo lvs | awk '{if ($4) {print "yes"} else {print "no"} }'
