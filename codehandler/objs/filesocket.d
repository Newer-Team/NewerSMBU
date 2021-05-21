objs\filesocket.o: src/filesocket.cpp src/globals.h ../include/cafe.h \
 ../include/types.h ../include/common.h ../include/gx2.h

:cmdList=cxppc  -c  -MD -I../include -bsp generic -cpu=espresso -object_dir=objs -Ogeneral --g++ --no_rtti -DREGION_Kinnay -DCODE_ADDR=0xf800000 -DDATA_ADDR=0x10400000 -filetype.cc src/filesocket.cpp -o objs\filesocket.o ; 
:cmdHash=0x4a35cb95
