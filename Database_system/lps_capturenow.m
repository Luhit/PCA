function []=lps_capturenow
try close figure 1;end;
vid=videoinput('winvideo',1,'YUY2_640x480');
while (1)
    choice=menu('Capture Now',...
                  'Intialize Camera',...
                  'Capture Image',...
                  'Save Image',...
                  'Exit');
    if (choice ==1)
        lps_inicamera(vid);
    end
    if (choice == 2)
        capcha=lps_capture(vid);
    end
    if (choice == 3)
        lps_saveimage(capcha);
    end   
    if (choice == 4)
        delete(vid);
        clc;
        close all;
        return;
    end    
end
end