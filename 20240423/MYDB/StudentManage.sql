CREATE DATABASE StudentManage
ON primary
(
name=StudentManage_data,
filename="d:\MYDB\StudentManage.mdf",
size=30,
maxsize=unlimited,
filegrowth=2
)
log on
(
name=StudentManage_log,
filename="d:\MYDB\StudentManage_Log.ldf",
size=15,
maxsize=30,
filegrowth=2
)
GO

sp_helpdb StudentManage

sp_renamedb StudentManage,StudentManage_new

