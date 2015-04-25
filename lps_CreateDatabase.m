function []=lps_CreateDatabase
cd Database_system;
while (1)
    choice=menu('Create Database',...
                    ' Add  an  Image',...
                    ' Add  a  Folder',...
                    ' Exit');
    if (choice ==1)
        lps_addimage;
    end
    if (choice == 2)
        lps_addfolder;
    end
    if (choice == 3)
        cd ..;
        clc;
        close all;
        return;
    end    
end
end