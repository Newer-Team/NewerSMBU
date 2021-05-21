objs\installer.o: src/installer.cpp ../include/cafe.h ../include/types.h \
 ../include/common.h ../include/gx2.h src/Code.h

:cmdList=cxppc  -c  -MD -I../include -bsp generic -cpu=espresso -object_dir=objs -Ogeneral --g++ --no_rtti -DREGION_Kinnay -DCODE_ADDR=0xf800000 -DDATA_ADDR=0x10400000 -filetype.cc src/installer.cpp -o objs\installer.o ; 
:cmdHash=0x20e6ba5d
