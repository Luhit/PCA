function [ OutputName ] = lps_FaceRec(m, A, Eigenfaces)
cd Test;
while (1)
    choice=menu('Face Recognition',...
                'Capture Now',...
                'Recognition',...
                'Exit');
    
    if (choice ==1)
        try cd Test;close all; end;
        lps_capturenow;

    end    
    if (choice ==2)
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
       number=int2str(n);
       disp(int2str(n));
       lps_door(number);
    end
     
   if (choice ==3) 
       
       
       return;
    end    
end

