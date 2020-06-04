caffe model files:
- .caffemodel và .pb: đây là những mô hình; họ nhị phân và thường là các tệp lớn
 + caffemodel: từ Caffe gốc
 + pb: từ Caffe2 và thường có init và dự đoán cùng nhau
- .pbtxt: dạng có thể đọc được của tệp pb Caffe2
- deploy.prototxt: mô tả kiến ​​trúc mạng để triển khai (và không đào tạo) thời gian 
- solver.prototxt: mô tả các biến được sử dụng trong quá trình đào tạo, bao gồm tỷ lệ học tập, chính quy, v.v.
- train_val.prototxt: mô tả kiến ​​trúc mạng cho thời gian đào tạo (và xác nhận)

- Chạy script execute_0_create_file_list để tạo file "dataset/training_list.txt"
  => điều kiện là trong thư mục "datasets/training_images" đã có image đã được tạo từ gather_training_data.py
	cấu trúc file này rất là hay đó là: image_name id_label
	ví dụ: 0000301.FE.1.png 2

- Chạy script execute_1_create_lmdb_database để tạo "dataset/training_set_lmdb"
	+ data.mdb
	+ lock.mdb

- execute_2_create_mean_image tạo file "dataset/mean_training_image.binaryproto"

gather_training_data.py sử dụng thằng này để detection image từ cam và save image vào 'datasets/training_images'

##### Initialize all labels
##### categories = [ 'Angry', 'Disgust', 'Fear', 'Happy' , 'Neutral',  'Sad', 'Surprise']
##### suffixes   = [ 'AN',    'DI',      'FE',   'HA',     'NE',       'SA',  'SU'      ]
##### pickFrom   = [  0,       1,         2,      3,        4,          5,     6        ] # Only prompt user for emotions in this list


- get all image files in folder dirImage input

- with a image :
  + generate a random integer labels (pickFrom)
	+ get emotion string (categories)
	+ get file suffyx
	+ detect faces in frame
	+ if face eexists : saveAcceptedImage()
	+ file name template "0000000.HA.0.png"

- jitterImage : Trả về một số phiên bản bị xáo trộn của hình ảnh đầu vào

	Total : 11 image

process_dataset.py

+ chức năng đọc và phân loại dataset
+ output ra 1 ma trận tính toán độ chính xác của nó

- Error khi chạy các script:

+ Check failed: *ptr host allocation of size 1824921600 failed : thiếu bộ nhớ
+ db_lmdb.hpp:15] Check failed: mdb_status == 0 (2 vs. 0) No such file or directory : thay đổi đường dẫn thư mục validation_set_mldb
