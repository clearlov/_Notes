/**
 * typeof():  number string boolean
			  undefined
			  object: null v={} v=new Object() v=[] v=new Array() function F(){}
			  function( v = function(){} )
 * .constructor:	Number String Boolean
					Object: v={}   v=new Object()
					Array: v=[]  v=new Array()
					Function: v=function(){}
					className: function className(){}
					--> it cant check null and undefined
					--> v && v.constructor   to test .constructor
					--> (10).constructor  (NaN).constructor
 */ 
