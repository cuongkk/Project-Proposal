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
    money INT,
	image_path VARCHAR(255)
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
    id_Product VARCHAR(6),
    quantity INT NOT NULL,
    price INT NOT NULL,
    PRIMARY KEY (id_Bill, id_Product),
    FOREIGN KEY (id_Bill) REFERENCES Bill(id_Bill),
    FOREIGN KEY (id_Product) REFERENCES Products(id)
);

CREATE TABLE Cart_Details (
    id_User VARCHAR(6),
    id_Product VARCHAR(6),
    quantity INT NOT NULL,
    price INT NOT NULL,
    PRIMARY KEY (id_User, id_Product),
    FOREIGN KEY (id_Product) REFERENCES Products(id)
);


INSERT INTO User (id, username, password, name, fullname, email, phoneNumber, money, image_path)
VALUES
('US0001', 'admin', 'admin', 'admin', null, null, null, null, '../backend/images/user/user.jpg'),
('US0002', 'nguyentuancuong', '123456', 'cuong', N'Nguyễn Tuấn Cường', N'ntuancuong2005@gmail.com', '0328228324', '100000', '../backend/images/user/user.jpg');

