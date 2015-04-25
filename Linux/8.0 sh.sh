appellation = "Lef Well"   
appellation = 100         # redefine
scores=(1,3,4,5)
scores[4]=8
const = 1000
readonly const            # unchangeable
unset const               # unset a variable

source "./b.sh"   # run ./b.sh
. ./b.sh          # run ./b.sh


now=`date`      # call system date command
user=`who | wc -l`
up=`date; uptime`

fn(){
  echo "args[0] = $1"
  echo "args = $[*]"
  return 100;
}

unset .f fn

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
# -d $dir   is a $dir
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
if[-z appellation -a $const !=0]      
then 
  s=`expr $const + 4`     #1004
  c=`expr $const \* 2`
elif []
else []
fi
  
for skill in 1 2 3 4 5      # for $str in "Hello, Lef Well!"
do
  echo $$       # pid of current process
  echo $0       # pwd
  echo $*       # all parameters that passed by command line
  echo $@       
  echo $n       # *(argv+n)
  echo $#       # int argc
  echo $?       # exit status, 0 on success; 1 on error
  echo -e "\n"  # disable escape char '\'
  echo '\n'     # 
  printf "\n"   # "\n"
  printf "%d %s\n" 100 "Lef Well"
  
  
  echo ${scores[0]}
  echo ${scores[*])}   # 
  echo ${scores[@])}   # 
  echo ${#scores[*]}   # sizeof(scores)
  echo ${#scores[0]}   # strlen(scores[0])
  
  echo ${#now}  # strlen($now)
  echo ${now:0,3}   # substr($now)
  
  echo ${now:-"2015-05-05"}   # now ? now : "2015-05-05"
  echo ${user:=1}             # if(!user) user = 1
  echo ${up:?"error msg"}
  echo ${now:+"NOW"}           # now && "NOW"
  echo "$appellation"
done