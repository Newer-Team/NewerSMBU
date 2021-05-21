objs\exceptionhandlers.o: src/exceptionhandlers.cpp ../include/cafe.h \
 ../include/types.h ../include/common.h ../include/gx2.h src/globals.h

:cmdList=cxppc  -c  -MD -I../include -bsp generic -cpu=espresso -object_dir=objs -Ogeneral --g++ --no_rtti -DREGION_Kinnay -DCODE_ADDR=0xf800000 -DDATA_ADDR=0x10400000 -filetype.cc src/exceptionhandlers.cpp -o objs\exceptionhandlers.o ; 
:cmdHash=0x0b798b93
