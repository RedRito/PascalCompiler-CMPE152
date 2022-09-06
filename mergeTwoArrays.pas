{
    Author Brandon Luong
    Date 08/29/2022
}
program MergeTwoArrays;
uses crt;                                       (*Used for checking input*)
    var
        array1: array[1..20] of Integer;        (*Array 1 max 20 values*)
        array2: array[1..20] of Integer;        (*Array 2 max 20 values*)
        mergedArray: array[1..40] of Integer;   (*Merged array max 40 values*)
        input: Integer;                         (*keyboard input*)
        ArrayLength: Integer;                   (*Used to measure array 1 length*)
        ArrayLength2: Integer;                  (*used to measure array 2 length*)
    
    //prints the given array
    procedure PrintArray(num: Integer; var arr: array of Integer);
    var i : Integer;
    begin
        //loop through and print value at given index
        for i:= 0 to num - 1 do
            writeln('Array[', i + 1,'] is ', arr[i]);
    end;
    
    //merged two given arrays num1 = length of arr1, num2 = length of array 2, arr1 = array 1, arr2 = array 2, mergedArray = array that is being merged into
    procedure MergeArray(num1, num2: Integer; var arr1, arr2, mergedArray: array of Integer);
    var i: Integer = 0;
        j: Integer = 0;
        index: Integer = 0;
    begin
        //loop through both arrays
        while (i < num1) and (j < num2) do
            begin
            //stores smaller element into merged array. Increment index of the array that is stored in the merged array. Increase the size of the merged array.
            if(arr1[i] < arr2[j]) then
                begin
                    mergedArray[index] := arr1[i];
                    index := index + 1;
                    i := i + 1;
                end
            else
                begin
                    mergedArray[index] := arr2[j];
                    index := index + 1;
                    j := j + 1;
                end;
            end;
        //store rest of arr1 into merged array (already sorted)
        while(i < num1) do
            begin
                mergedArray[index] := arr1[i];
                index := index + 1;
                i := i + 1;
            end;
        //store rest of arr2 into merged array (already sorted)
        while(j < num2) do
            begin
                mergedArray[index] := arr2[j];
                index := index + 1;
                j := j + 1;
            end;
    end;
    
    
    begin
    //read array 1
    writeln('Enter Array 1 (Enter any char to exit): ');
    ArrayLength := 0;
    while not eoln do
        begin
        {$I-}                   (* Disabled I/O type checking to check for invalid input*)
        read(input);
        {$I+}
        if ioresult=0 then  (* Manually check if the inputted value matches types*)
            begin
            ArrayLength := ArrayLength + 1;
            array1[ArrayLength] := input;
            end
        else
            begin
            writeln('invalid input');
            break;
            end;
        end;
    //resets the cr lf
    readln;
    //read array 2
    writeln('Enter Array 2 (Enter any char to exit): ');
    ArrayLength2 := 0;
    while not eoln do
        begin
        {$I-}                   (* Disabled I/O type checking to check for invalid input*)
            read(input);
        {$I+}
            if ioresult=0 then  (* Manually check if the inputted value matches types*)
                begin
                ArrayLength2 := ArrayLength2 + 1;
                array2[ArrayLength2] := input;
                end
            else
                begin
                writeln('invalid input');
                break;
                end;
        end;
    
    //Print both arrays
    writeln('Array 1');
    PrintArray(ArrayLength, array1);
    writeln('Array 2');
    PrintArray(ArrayLength2, array2);
    
    //merge arrays
    MergeArray(ArrayLength, ArrayLength2, array1, array2, mergedArray);
    
    //print the merged array
    writeln('Merged Array');
    PrintArray(ArrayLength + ArrayLength2, mergedArray);
    
end.
        




