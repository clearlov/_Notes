What with function overloading,function templates,and function template overloadin
C++ needs,and has,a well-defined strategy for deciding which function definition to 
for a function call,particularly when there are multiple arguments.The process is called
overload resolution.Detailing the complete strategy would take a small chapter,so let¡¯s ta
just a broad look at how the process works:
    Phase 1¡ªAssemble a list of candidate functions.These are functions and templa
functions that have the same names as the called functions.
    Phase 2¡ªFrom the candidate functions,assemble a list of viable functions.Thes
are functions with the correct number of arguments and for which there is an
implicit conversion sequence,which includes the case of an exact match for each
type of actual argument to the type of the corresponding formal argument.For
example,a function call with a type float argument could have that value con-
verted to a double to match a type double formal parameter,and a template cou
generate an instantiation for float.
    Phase 3¡ªDetermine whether there is a best viable function.If so,you use that
function.Otherwise,the function call is an error.