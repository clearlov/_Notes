" /usr/share/vim/vim74/syntax/txt.vim
" :set syntax=txt
" oneline    
" ms=s+1 me=s-1 ms(Match Start) me(Match End) s (Start of Match) e(End
" of Match)
"   me=e+1 Match End to the last words  
"   e.g. start="if\s*("ms=e+1    end=")"me=s-1   ==> if(a==b) match a==b
"
" Vim syntax file
" Language:	txt  (Vince-Well)
" Maintainer:	Vince Well <vince.i.well@gmail.com>
" Last Change:	2014 Oct 31

" Quit when a (custom) syntax file was already loaded
if exists("b:current_syntax")
  finish
endif

syn keyword	confTodo	contained TODO FIXME XXX
" Avoid matching "text#text", used in /etc/disktab and /etc/gettytab

" match comment
syn match	confComment	"^//.*" contains=confTodo
syn match	confComment	"\s//.*"ms=s+1 contains=confTodo
" block comments
syn region   xString start="/*" end="*/"


" match titles like README.md
syn match	confComment	"^#[^#].*" contains=confTodo 
syn match	confComment	"^##[^#].*" contains=confTodo
syn match	confComment	"^###[^#].*" contains=confTodo
syn match	confComment	"^####[^#].*" contains=confTodo

syn region	confString	start=+"+ skip=+\\\\\|\\"+ end=+"+ oneline
syn region	confString	start=+'+ skip=+\\\\\|\\'+ end=+'+ oneline

" Define the default highlighting.
" Only used when an item doesn't have highlighting yet
hi def link confComment	Comment
hi def link confTodo	Todo
hi def link confString	String

let b:current_syntax = "txt"

" vim: ts=8 sw=2
