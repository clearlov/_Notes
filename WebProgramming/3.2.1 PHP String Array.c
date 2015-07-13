/**
 * PHP foreach
 * @see http://www.laruence.com/2008/11/20/630.html
 */


/*
    foreach($arr as $k => $v){
      echo $k . '=>' .$v ."\n";
    }
 */
unticked_statement:
  | T_FOREACH '(' variable T_AS {
      /**
       * zend_do_foreach_begin("foreach", '(', $arr, "as", 1 TSRMLS_CC)
       * @note to opcode
       *  FE_RESET reset the array pointer to the first element
       *  FE_FETCH
       */
      zend_do_foreach_begin(&$1, &$2, &$3, &$4, 1 TSRMLS_CC);
     }
     foreach_variable foreach_optional_arg ')' {
       /**
        * zend_do_foreach_cont("foreach", '(', "as", $k, $v TSRMLS_CC)
        * @note to opcode
        *
        */
       zend_do_foreach_cont(&$1, &$2, &$4, &$6, &$7 TSRMLS_CC);
     }
     foreach_statement {
       //zend_do_foreach_end("foreach", "as")
       zend_do_foreach_end(&$1, &$4 TSRMLS_CC);
     }

  | T_FOREACH '(' expr_without_variable T_AS {
      zend_do_foreach_begin(&$1, &$2, &$3, &$4, 0 TSRMLS_CC);
      }
     variable foreach_optional_arg ')' {
       zend_check_writable_variable(&$6);
       zend_do_foreach_cont(&$1, &$2, &$4, &$6, &$7 TSRMLS_CC);
     }
     foreach_statement {
       zend_do_foreach_end(&$1, &$4 TSRMLS_CC);
     }
     ;
/*
 ********************************The OPCODE***********************
 * @param op
 *  FE_RESET http://php.net/manual/en/internals2.opcodes.fe-reset.php
 *    Initialize an iterator on array-value.  If the array is empty, jump to address.  
 *    Followed by FE_FETCH.
 *  FE_FETCH http://php.net/manual/en/internals2.opcodes.fe-fetch.php
 *    Fetch an element from iterator.  If no element is available, jump to address.  
 *    Followed by ZEND_OP_DATA
 *  CONCAT http://php.net/manual/en/internals2.opcodes.concat.php
 *    Concats string values string1 and string2
 * @param int ext 
 * @operands array operand1[, operand2]
 *  operand1 the param to opcode
 *  operand2 if error
 * @note operand number: op_type symbol + union(int)
 *  op_type(symbol)
 *    IS_CONST
 *    IS_TMP_VAR(~)    e.g. ~5
 *    IS_VAR($)        e.g. $2
 *    IS_UNUSED
 *    IS_CV(!) cached value, union is an address  e.g. !0
 ******************************************************************
 function name:  (null)
 number of ops:  17
 compiled vars:  !0 = $arr, !1 = $k, !2 = $v
 line     #  op             ext  return  operands
 -------------------------------------------------------------------------------
 2        0  SEND_VAL                    1
          1  SEND_VAL                    100
          2  DO_FCALL       2            'range'
          3  ASSIGN                      !0, $0
 3        4  FE_RESET            $2      !0, ->14   // operand 2: ->14  if erro jump to #14 SWITCH_FREE
          5  FE_FETCH            $3      $2, ->14
          6  ZEND_OP_DATA        ~5
          7  ASSIGN                      !2, $3
          8  ASSIGN                      !1, ~5
 4        9  CONCAT              ~7      !1, '-'
          10  CONCAT             ~8      ~7, !2
          11  CONCAT             ~9      ~8, '%0A'
          12  ECHO                       ~9
 5        13  JMP                        ->5        // operand 1: ->5  jump to #5 FE_FETCH
          14  SWITCH_FREE                $2         // end of loop
 7        15  RETURN                     1
          16* ZEND_HANDLE_EXCEPTION
 */
