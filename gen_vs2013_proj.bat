if not exist build mkdir build
cd build

REM Update your dependency directories below as necessary

cmake -G"Visual Studio 12" -DOpenCV_DIR="C:\libs\opencv-2.4.10\build" -DSFML_ROOT="C:\libs\SFML-2.2" -DPROTOBUF_SRC_ROOT_FOLDER="C:\libs\protobuf-2.6.1" ..
cd ..

xcopy .\samples-aux\vs2013\copy_to_bin_dir\*.* .\build\bin\Debug\ /E /Y
xcopy .\samples-aux\vs2013\copy_to_bin_dir\*.* .\build\bin\Release\ /E /Y
xcopy .\samples-aux\vs2013\copy_to_bin_dir\*.* .\build\bin\RelWithDebInfo\ /E /Y
