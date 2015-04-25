function [ OutputName ] = lps_FaceRec(m, A, Eigenfaces)
cd Test;
while (1)
    choice=menu('Face Recognition',...
                'Input Image From File',...
                'Capture Now',...
                'Recognition',...
                'Exit');
    if (choice ==1)
       try cd Test;close all; end; 
         ChooseFile = imgetfile;
         capcha = imread(ChooseFile);
         %capcha = imcrop(capcha,[180,20,280,380]);
         imshow(capcha);
         lps_saveimage(capcha);
    end
    if (choice == 2)
        try cd Test;close all; end;
        lps_capturenow;

    end    
    if (choice == 3)
       OutputName=lps_Recognition(m, A, Eigenfaces);
       n=((OutputName+1)/2);
       
       im=imread('InputImage.jpg');
       cd ..;
       img=strcat('Database_system\s',int2str(n),'\1.jpg');
       SelectedImage=imread(img);
       subplot(121);
       imshow(im)
    title('Test Image');
    subplot(122),imshow(SelectedImage);
    title('Equivalent Image');
       disp('Student No');
       disp(int2str(n));
       
    end
     
   if (choice == 4) 
       clc; 
       close all;
       return;
    end    
end

