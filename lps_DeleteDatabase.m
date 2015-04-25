function [ ] = lps_DeleteDatabase()
disp('Please dont delete in between');
cd Database_system
 while (1)
    choice=menu('Delete DataBase',...
                'Delete an Image',...
                'Delete a Folder',...               
                'Exit');
    if (choice ==1)
        ChooseFile=imgetfile;
        delete(ChooseFile);
    end
    if (choice == 2)
        delfolder=uigetdir('F:\code\face_by_lps\Database_system','Delete Folder');
        rmdir(delfolder,'s');
    end    
    if (choice == 3)
        cd ..
        clc;
        close all;
        return;
    end    
end
