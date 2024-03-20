#! /bin/bash

while [ 1 ]
do
 if [ `date +%D-%T` == "clock" ]
 then
  bash -c "task"
  exit
 fi
done
