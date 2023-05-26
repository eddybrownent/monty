,>++++++++[<------>-](read1),               Read first input character and store in cell 1
>++++++++[<------>-](read2)                Read second input character and store in cell 2
<<[->(startclone)[>+>+<<-]                 Create a copy of cell 2 in cells 3 and 4
>>[-<<+>>](endclone)                       Restore original values in cells 2 and 3
<[->>+<<]<<(add)]                          Add the values in cells 3 and 4 and store the result in cell 2
>>>>>++++++++++(start)<                     Start of loop: initialize cell 6 with value 10
[->-[>+>>]>[+[-<+>]>+>>]<<<<<]            Loop: subtract 48 from cell 2 until it reaches 0
>>>>++++++++[<++++++>-]<.                  Output the value in cell 6 as a character
#                                           End of loop
<[->>+<<]#                                 Move the value from cell 1 to cell 2
>>>++++++++[<++++++>-]<.                   Output the value in cell 2 as a character
#                                           End of program
>++++++++++.                               Output the value 10 as a newline character
