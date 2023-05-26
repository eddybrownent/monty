,>++++++++[<------>-](read1),       Read first input character and store in cell 1
>++++++++[<------>-](read2)        Read second input character and store in cell 2
<<[->(startclone)[>+>+<<-]         Create a copy of cell 2 in cells 3 and 4
>>[-<<+>>](endclone)               Restore original values in cells 2 and 3
<[->>+<<]<<(add)]                  Add the values in cells 3 and 4 and store the result in cell 2
>>>>>++++++++[<++++++>-]<.         Increment cell 5 and output its corresponding character

