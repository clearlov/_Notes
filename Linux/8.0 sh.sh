#!/bin/bash
########################## Stream #################################
read -p "Your Name:" -t 10 name
    -p "Hint: "     # hint
    -t 10           # 10 sec

########################## FILE ###################################
filename="$(pwd)/lef.cc"
if [ -f ${filename} -a ${filename##*.} ]
then
    echo ${filename##*.}     # get the extension
fi

######################### STRING ##################################
echo "Hello, $name"
${name^^}       # uppercase()


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





appellation="Lef Well"   
appellation=100         # redefine
scores=(1,3,4,5)
scores[4]=8
const_num = 1000
readonly const_num            # unchangeable
unset const_num               # unset a variable

declare [-aixr] VAR 
    -a array
    -i int
    -x 
    -r readonly
declare -i sum = $RANDOM*10/32768  # $RANDOM = [0, 32767]


source "./b.sh"   # run ./b.sh
. ./b.sh          # run ./b.sh

DATE=$(date)        # DATE=`date`   call system date command
USER=$(who | wc -l)
DATE_UPTIME=$(date; DATE_UPTIMEtime)

echo -e "\n"  # disable escape-char '\'
echo '\n'     # 
printf "\n"   # "\n"
printf "%d %s\n" 100 "Lef Well"

echo ${scores[0]}
echo ${scores[*])}   # 
echo ${scores[@])}   # 
echo ${#scores[*]}   # sizeof(scores)
echo ${#scores[0]}   # strlen(scores[0])

echo ${#DATE}  # strlen($DATE)
echo ${DATE:0:3}   # substr($DATE)

echo ${DATE:-"2015-05-05"}   # DATE || "2015-05-05"
echo ${USER:=1}             # if(!USER) USER = 1
echo ${DATE_UPTIME:?"error msg"}
echo ${DATE:+"DATE"}           # DATE && "DATE"
echo "$appellation"


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
if [-z $appellation -a $const_num !=0]      
then 
  s=`expr $const_num + 4`     #1004
  c=`expr $const_num \* 2`
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

for((i=1;i<100;++i))
do
  echo $i;
done



case ${file:0:2} in
  "cn")
    echo "China"
    ;;
  "en")
    echo "USA"
    ;;
  *)
    echo "default"
    ;;
esac

select opt in "Lef" "Well";
  do
    case $opt in
      "Lef")
        echo "First Name: Lef"
        ;;
      "Well")
        echo "Last Name: Well"
        ;;
    esac
  done




