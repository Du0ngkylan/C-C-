refs: https://github.com/danduncan/HappyNet


### Tạo 2 thư mục Happy và Sad chứa các image và label tương ứng.
- run : gather_training_data.py
- output: 2 folder train_images và val_images

### 1, Create file list (train.txt và val.txt)

- Format của file train.txt là {image_name -- label}
- ['HA', 'SA']

### 2, Create lmdb database

- input: train_images, train.txt
- run: train_set_lmdb
- output: lock file và data file

thực hiện tương tự với val_images

### 3, Create mean image

- train_set_lmdb ==========> *.binaryproto

### 4, Train custom model

- solver.protxt ----------> {*.caffemodel, *.solverstate}












