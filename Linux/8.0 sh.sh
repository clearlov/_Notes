#!/bin/bash

########################## FILE ###################################
FILENAME="$(pwd)/lef.cc"
if [ -f ${FILENAME} -a ${FILENAME##*.} ]
then
    echo ${FILENAME##*.}     # get the extension
fi


######################### STRING ##################################
read NAME
echo "Hello, $NAME"
${NAME^^}       # uppercase()


######################### PROCESS #################################
rand=$RANDOM
bash            # create a child shell bash, and parent bash is sleeping
echo ${rand}    # nothing
exit            # back to parent process

export rand
bash
echo ${rand}    # e.g. 32767
unset ${rand}   # child process's ${rand} is unseted, not the parent's
exit

echo ${rand}    # e.g. 32767





APPELLATION="Lef Well"   
APPELLATION=100         # redefine
SCORES=(1,3,4,5)
SCORES[4]=8
CONST_NUM = 1000
declare [-aixr] VAR 
    -a array
    -i int
    -x 
    -r readonly
declare -i sum = $RANDOM*10/32768  # $RANDOM = [0, 32767]
readonly CONST_NUM            # unchangeable
unset CONST_NUM               # unset a variable

source "./b.sh"   # run ./b.sh
. ./b.sh          # run ./b.sh

DATE=$(date)        # DATE=`date`   call system date command
USER=$(who | wc -l)
DATE_UPTIME=$(date; DATE_UPTIMEtime)

echo -e "\n"  # disable escape char '\'
echo '\n'     # 
printf "\n"   # "\n"
printf "%d %s\n" 100 "Lef Well"

echo ${SCORES[0]}
echo ${SCORES[*])}   # 
echo ${SCORES[@])}   # 
echo ${#SCORES[*]}   # sizeof(SCORES)
echo ${#SCORES[0]}   # strlen(SCORES[0])

echo ${#DATE}  # strlen($DATE)
echo ${DATE:0:3}   # substr($DATE)

echo ${DATE:-"2015-05-05"}   # DATE ? DATE : "2015-05-05"
echo ${USER:=1}             # if(!USER) USER = 1
echo ${DATE_UPTIME:?"error msg"}
echo ${DATE:+"DATE"}           # DATE && "DATE"
echo "$APPELLATION"


fn(){
  echo "args[0] = $1"
  echo "args = $[*]"
  return 100;
}

unset .f fn         # .f is necessary

# STDIN_FILENO(0)  STDOUT_FILENO(1)  STDERR_FILENO(2)
command < $file    # stdin reads from $file instead of keyboard
command 2 > $file   # save stderr to $file instead of printing on screen
command 1 >> $file  # append stdout to $file
command > $file 2>&1 #  combine stderr stdout to $file
command >> $file 2>&1
command < $file_in > $file_out  # save stdin to $file_in; stdout to $file_out
command > /dev/null # normally use for daemon process - run without stdout
command > /dev/null 2>&1

# -o(or) -a(and) !(not)
# ==(-eq) !=(-ne) -gt -lt -ge(great and equal) -le
# -z $str (isempty($str)  -n $str (!isempty($str))
# -b $file  is $file a device file
# -c $file  is $file a character device file
# -d $dir   is $dir a directory
# -f $file  is a normal file (either a device nor a character file)
# -g $file  is setting SGID bit
# -k $file  is setting Stricky bit
# -p $file  is a pipe
# -u $file  is setting SUDI bit
# -r $file  is readble
# -w $file  is writable
# -x $file  is executable
# -s $file  is filesize($file) == 0
# -e $path  is $path exist
if [-z $APPELLATION -a $CONST_NUM !=0]      
then 
  s=`expr $CONST_NUM + 4`     #1004
  c=`expr $CONST_NUM \* 2`
elif []
else []
fi
  
for skill in 1 2 3 4 5      # for $str in "Hello, Lef Well!"
do
  echo $$       # pid of current process
  echo $0       # pwd
  echo $*       # all arguments that passed by command line
  echo $@       
  echo $n       # *(argv+n)
  echo $#       # int argc
  echo $?       # exit status, 0 on success; 1 on error
done







