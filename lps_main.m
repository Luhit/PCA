%Main
close all
clear all
clc
while (1)
    choice=menu('Face Recognition System',...
                'Create Database of Faces',...
                'Delete DataBase',...
                'Train System',...
                'Face Recognition',...
                'Exit');

    if (choice ==1)
        lps_CreateDatabase;
    end
    
    if (choice == 2)
        lps_DeleteDatabase;
    end
    
    if (choice ==3)
        [m, A, Eigenfaces]=lps_Trainit;
    end
    if (choice == 4)
        if exist('train.mat');
            load train;
        end
        lps_FaceRec(m, A, Eigenfaces);
    end
   
    if (choice == 5)
        clear all;
        clc;
        close all;
        return;
    end    
    
end
