objs\filesystem.o: src/filesystem.cpp ../include/cafe.h ../include/types.h \
 ../include/common.h ../include/gx2.h src/globals.h src/socketstuff.h

:cmdList=cxppc  -c  -MD -I../include -bsp generic -cpu=espresso -object_dir=objs -Ogeneral --g++ --no_rtti -DREGION_Kinnay -DCODE_ADDR=0xf800000 -DDATA_ADDR=0x10400000 -filetype.cc src/filesystem.cpp -o objs\filesystem.o ; 
:cmdHash=0x5a3fe217
