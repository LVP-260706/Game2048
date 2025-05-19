# Game2048
Họ và tên: Lâm Việt Phúc  
Mã sinh viên: 24021597  
Mức điểm mong muốn: 7.5 - 8.5
## Giới thiệu chung
2048 được lấy cảm hứng từ https://play2048.co/  
Game được viết bằng ngôn ngữ C++ và sử dụng thư viện SDL2
### Luật chơi
- **Người chơi sẽ được cấp cho một bảng kích cỡ 4x4 với 2 ô số mở đầu (10% là số 4 và 90% là số 2) những ô có cùng giá trị sẽ sát nhập vào nhau và tạo ra một ô có giá trị gấp đôi. Nhiệm vụ của người chơi là sát nhập các ô một cách khéo léo để tạo ra ô chiến thắng 2048. Bằng cách**
  - Nhấn UP để dồn các ô lên phía trên
  - Nhấn DOWN để dồn các ô xuống phía dưới
  - Nhấn LEFT để dồn các ô sang bên trái
  - Nhấn RIGHT để dồn các ô sang bên phải
- **Mỗi khi 2 ô cùng giá trị và được sát nhập điểm của người chơi sẽ được công thêm bằng đúng giá trị của ô mới được tạo ra từ việc sát nhập**
### Mô tả chức năng
  - Nút Start để bắt đầu chơi
  - Có âm thanh sinh động
  - Có nút âm thanh để bật/tắt
  - Lưu điểm cao nhất mỗi lần chơi
  - Có bảng thông báo mỗi khi thắng hoặc thua
  - Có bảng Score cập nhật điểm liên tục và Best lưu trữ điểm cao nhất ngay cả khi tắt chương trình
### Các tính năng lập trình được sử dụng
  - Class/Struct
  - Bắt sự kiện bàn phím, chuột
  - Sinh số ngẫu nhiên
  - Tính điểm Score/Best vào file
  - Vector
  - Music + Button ON/OFF
  - Font
  - Menu + Button Restart/Home
  - Các lệnh vẽ hình ảnh, texture
  - Background
  - Tách file quản lý code
### Các nguồn tham khảo
  - Thuật toán sinh số ngẫu nhiên: https://www.youtube.com/watch?v=faUM8Xrod-I
  - Âm thanh: https://www.youtube.com/watch?v=bZA9fPmFok0
  - Hình ảnh: https://www.canva.com/
  - Code mẫu
  - Mức độ sử dụng AI: 30%
### Hướng phát triển
  - Thêm các cài đặt về âm thanh, danh sách điểm cao của các lần chơi ở Menu
  - Thêm các hiệu ứng khi các ô di chuyển
  - Bổ sung các hỗ trợ như Under hay đảo vị trí các ô
  - Tạo thêm lựa chọn các bảng khác nhau thay vì chỉ bảng 4x4
  - Mở rộng giới hạn các số lớn hơn 2048  
 **Lời cuối cùng em xin cảm ơn cô Trần Thị Minh Châu, thầy Lê Bằng Giang đã giúp đỡ và hướng dẫn em hoàn thành dự án game này.**
