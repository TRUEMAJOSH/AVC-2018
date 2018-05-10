#!/bin/sh
IP=pi@10.140.30.40
DIRPI=/home/pi/Desktop/
DIRPC="/mnt/d/Desktop/AVC-2018"
echo Deleting old c files
sshpass -p 'raspberry' ssh -x $IP 'cd $DIRPI; rm *.cpp'
echo Transfering files to PI
rsync -e 'sshpass -p 'raspberry' ssh -ax' -av $DIRPC $IP:$DIRPI
echo Compiling and Executing
sshpass -p 'raspberry' ssh -x $IP 'cd /home/pi/Desktop/AVC-2018;make;echo raspberry | sudo -S ./main'