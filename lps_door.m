function []=lps_door(number)
s=serial('COM7','BaudRate',9600); %The COM7 for my USB2RS232 it will be different for different port  
fopen(s);
if(number=='1')
        fprintf(s,'a');
        disp('pank');
elseif(number=='2')
        fprintf(s,'b');
        disp('luhit');

elseif(number=='3')
        fprintf(s,'c');
        disp('sundeep');
elseif(number=='4')
        fprintf(s,'d');
        disp('aman');
elseif(number=='5')
        fprintf(s,'e');
        disp('Miss Himakhi');
else
    disp('Invalid number');
end
fclose(s);
delete(s);
end