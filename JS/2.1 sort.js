/**
 * each a b, a < b ==> a,b   a = b  a > b ==> b,a
 * sort()
 */

 // function queue(a,b){return a-b}
function queue(){return arguments[0] - arguments[1];}
function reverse(){return -(arguments[0] - arguments[1]);}
function parity(a,b){return a%2 ? 1 : (b%2)}
var a = b = c = d = e = f = g = [3,1,2,4,5,9,2,0,8,2,7,6,8];
a.sort(queue);   	// 1 2 3 4
b.sort(reverse);	// 4 3 2 1
c.sort(pairty);		// 3 1 2 4
