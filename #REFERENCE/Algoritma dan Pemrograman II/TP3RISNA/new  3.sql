create database kontrak_matkul;
use kontrak_matkul;

create table mahasiswa(
	nim varchar(11) primary key,
	nama varchar(50) not null,
	jk varchar(2) not null,
	alamat varchar(50) not null
);

create table dosen(
	nip varchar(11) primary key,
	nama_dosen varchar(50) not null,
	jk varchar(2) not null,
	alamat varchar(50) not null
);

create table matkul(
	kd_matkul varchar(11) primary key,
	nama_matkul varchar(20) not null,
	sks int(2) not null
);

create table kontrak(
	id_kontrak varchar(11) primary key,
	nim varchar(11) not null,
	nip varchar(11) not null,
	kd_matkul varchar(11) not null,
	foreign key(nim) references mahasiswa(nim),
	foreign key(nip) references dosen(nip),
	foreign key(kd_matkul) references matkul(kd_matkul)
);

insert into mahasiswa(nim,nama,jk,alamat) values
('1403354','Faisal Syaiful Anwar','L','Bandung Asri'),
('1403351','Fikrry Muslim','L','Bandung City'),
('1403352','M Eagan Ramadhan','L','Lembang'),
('1403353','Muhammad Ridwan','L','Bandung Coret');

insert into dosen values 
('1234','Jajang Kusnendar','L','Bandung'),
('1235','Rosa Ariani','P','Makassar'),
('1236','Herbert Siregar','L','Cimahi'),
('1237','Eka Fitrajaya','L','Solokan'),
('1238','Asep Wahyudin','L','Garut');

insert into matkul values
('MK001','Basis Data','2'),
('MK002','Algoritma & Pemrograman 2','3'),
('MK003','Logika Informatika','2'),
('MK004','Kalkulus','3'),
('MK005','Programan Visual','2');

insert into kontrak values
(null,'1403351','1234','MK001'),
(null,'1403351','1235','MK002'),
(null,'1403351','1236','MK003'),
(null,'1403352','1237','MK001'),
(null,'1403352','1238','MK005'),
(null,'1403352','1234','MK004'),
(null,'1403353','1234','MK001'),
(null,'1403353','1235','MK002'),
(null,'1403353','1238','MK003');

select a.nim,a.nama,b.nama_matkul, b.sks
From mahasiswa a, matkul b, kontrak c
where a.nim=c.nim And b.kd_matkul=c.kd_matkul;

select a.id_kontrak,b.nama_matkul, c.nim
from kontrak a, matkul b, mahasiswa c
where a.nim = '1403351' and a.nim=c.nim and a.kd_matkul=b.kd_matkul;

select a.nim, a.nama, b.nama_matkul,d.nama_dosen
from mahasiswa a, matkul b, kontrak c,dosen d
where a.nim = c.nim and b.kd_matkul = c.kd_matkul and d.nip = c.nip and a.nim between '1403351' and '1403352';

update dosen Set nama_dosen="Sule Prikitiw",alamat="Garut city" where nip="1234";