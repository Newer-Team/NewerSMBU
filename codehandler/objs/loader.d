objs\loader.o: src/loader.cpp ../include/cafe.h ../include/types.h \
 ../include/common.h ../include/gx2.h ../include/nn.h src/globals.h \
 src/socketstuff.h src/exceptionhandlers.h

:cmdList=cxppc  -c  -MD -I../include -bsp generic -cpu=espresso -object_dir=objs -Ogeneral --g++ --no_rtti -DREGION_Kinnay -DCODE_ADDR=0xf800000 -DDATA_ADDR=0x10400000 -filetype.cc src/loader.cpp -o objs\loader.o ; 
:cmdHash=0xc081b07f
