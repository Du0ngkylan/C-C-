refs : https://www.pyimagesearch.com/2017/04/03/facial-landmarks-dlib-opencv-python/

Hướng dẫn sử dụng dlib và OpenCV để dectect "facial lanmarks" từ ảnh.

Các mốc trên khuôn mặt được sử dụng để khoanh vùng và
thể hiện các vùng nổi bật trên khuôn mặt, như:
- Eyes
- Eyebrows
- Nose
- Mouth
- Jawline

Cột mốc khuôn mặt đã được áp dụng thành công để căn chỉnh khuôn mặt,
ước tính tư thế đầu, hoán đổi khuôn mặt, phát hiện chớp mắt và nhiều hơn nữa.

#### 1, Chính xác các mốc trên khuôn mặt là gì và cách chúng hoạt động.
#### 2, Cách phát hiện và trích xuất các mốc trên khuôn mặt từ một hình ảnh bằng cách sử dụng dlib, OpenCV và Python.


Facial landmarks with dlib, OpenCV, and Python

What are facial landmarks?

Phát hiện các mốc trên khuôn mặt là một tập hợp con của vấn đề dự đoán hình dạng.
Đưa ra một hình ảnh đầu vào (và thông thường là ROI chỉ định đối tượng quan tâm),
một công cụ dự đoán hình dạng cố gắng bản địa hóa các điểm quan tâm chính dọc theo hình.



Trong bối cảnh các mốc trên khuôn mặt,
mục tiêu của chúng tôi là phát hiện các cấu trúc khuôn mặt quan trọng trên khuôn mặt bằng các phương pháp dự đoán hình dạng.

Do đó, phát hiện các mốc trên khuôn mặt là một quá trình gồm hai bước:

#### Bước #1: Xác định các khuôn mặt trong hình ảnh.
#### Bước #2: Phát hiện các cấu trúc khuôn mặt quan trọng trên ROI khuôn mặt.

Nhận diện khuôn mặt (Bước #1) có thể đạt được bằng một số cách.

- Chúng ta có thể sử dụng thác Haar tích hợp OpenCV.
- Chúng tôi có thể áp dụng trình phát hiện đối tượng HOG + tuyến tính SVM được đào tạo trước cho nhiệm vụ phát hiện khuôn mặt.
Hoặc thậm chí chúng ta có thể sử dụng các thuật toán dựa trên learning-based khuôn mặt.


Trong cả hai trường hợp, thuật toán thực tế được sử dụng để phát hiện khuôn mặt trong ảnh không phải là vấn đề.
Thay vào đó, điều quan trọng nhất là thông qua một số phương pháp,
chúng ta có được hộp giới hạn khuôn mặt (tức là, (x, y) - các tọa độ của khuôn mặt trong hình ảnh)

=> Với vùng mặt sau đó chúng ta có thể áp dụng Bước #2: phát hiện các cấu trúc khuôn mặt quan trọng trong vùng khuôn mặt.


Có nhiều loại máy detection facial landmark, nhưng về cơ bản,
tất cả các phương pháp đều cố gắng xác định và gắn nhãn cho các vùng trên khuôn mặt sau:

- Mouth
- Right eyebrow
- Left eyebrow
- Right eye
- Left eye
- Nose
- Jaw

Máy detection facial landmark mặt được bao gồm trong thư viện dlib
là một triển khai của Căn chỉnh khuôn mặt một phần nghìn giây với một bài tập về cây hồi quy của Kazemi và Sullivan (2014).

Phương pháp này bắt đầu bằng cách sử dụng:

=> Một tập huấn của các facial landmark được dán nhãn trên một hình ảnh.
Những hình ảnh này được dán nhãn thủ công, chỉ định cụ thể (x, y) các phối hợp của các vùng xung quanh mỗi cấu trúc khuôn mặt.


Với dữ liệu huấn luyện này, một nhóm các cây hồi quy được đào tạo để ước tính các vị trí mốc trên mặt
trực tiếp từ chính cường độ điểm ảnh (tức là, không có tính năng trích xuất tính năng nào xảy ra.


Kết quả cuối cùng là một máy detection facial landmark có thể được sử dụng để phát hiện các mốc trên khuôn mặt
trong thời gian thực với các dự đoán chất lượng cao.

Understanding dlib’s facial landmark detector

Máy dò mốc mặt được đào tạo trước trong thư viện dlib được sử dụng để ước tính vị trí của 68 (x, y)
- điều phối ánh xạ tới các cấu trúc khuôn mặt trên khuôn mặt.


Bất kể tập dữ liệu nào được sử dụng, cùng một khung dlib có thể được sử dụng để huấn luyện bộ dự báo hình dạng trên dữ liệu huấn luyện đầu vào
- điều này hữu ích nếu bạn muốn đào tạo máy dò mốc mặt hoặc bộ dự đoán hình dạng tùy chỉnh của riêng bạn.


Detecting facial landmarks with dlib, OpenCV, and Python

