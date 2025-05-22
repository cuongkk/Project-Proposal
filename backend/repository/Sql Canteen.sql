CREATE DATABASE Canteen_Management;

USE Canteen_Management;
CREATE TABLE Products (
    id VARCHAR(6) PRIMARY KEY,
    name NVARCHAR(100) NOT NULL,
    inf NVARCHAR(100) NOT NULL,
    category NVARCHAR(50) NOT NULL,
    price INT NOT NULL,  
    discount INT NOT NULL,
    quantity INT NOT NULL,
    manufacture_date DATE,
    expiry_date DATE,
    image_path VARCHAR(255)
);

CREATE TABLE User (
    id VARCHAR(6) PRIMARY KEY,
    username VARCHAR(100) NOT NULL,
    password VARCHAR(100) NOT NULL,
    name NVARCHAR(100) NOT NULL,
    fullname NVARCHAR(100),
    email NVARCHAR(100),
    phoneNumber VARCHAR(10),
    money INT
);

CREATE TABLE Bill (
    id_Bill VARCHAR(6) PRIMARY KEY,
    id_User VARCHAR(6) NOT NULL,
    totalCost INT NOT NULL,
    paid_date DATE,
    FOREIGN KEY (id_User) REFERENCES User(id)
);

CREATE TABLE Bill_Details (
    id_Bill VARCHAR(6),
    id_Products VARCHAR(6),
    quantity INT NOT NULL,
    price INT NOT NULL,
    PRIMARY KEY (id_Bill, id_Products),
    FOREIGN KEY (id_Bill) REFERENCES Bill(id_Bill),
    FOREIGN KEY (id_Products) REFERENCES Products(id)
);

-- Thêm dữ liệu mẫu
INSERT INTO Products (id, name, inf, category, price, discount, quantity, manufacture_date, expiry_date, image_path)
VALUES 
('SP0001', N'Bánh Mì', N'Bánh', N'Đồ ăn', 15000, 10, 10, '2024-01-01', '2027-01-01', 'images/laptop.jpg'),
('SP0002', N'Nước Suối', N'Nước', N'Đồ uống', 10000, 5, 50, '2024-03-01', '2025-03-01', 'images/mouse.jpg');

INSERT INTO User (id, username, password, name, fullname, email, phoneNumber, money)
VALUES
('US0001', 'admin', 'admin', 'admin', null, null, null, null);

use master
drop database Canteen_Management