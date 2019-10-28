
#CAROSSROOT:=/home/soloicesky/developementTools/arm/usr/bin
#CAROSSROOT:=
#CC:= $(CAROSSROOT)/arm-linux-gcc
CC:= gcc
AR:= ar
CFLAGS:= -shared -fPIC -Wall
SRC = $(wildcard SRC/*.c)
OBJS = $(SRC:.c=.o)
PROJECTNAME := Crypto


TARGET = libCrypto.so

all:$(OBJS)
	$(CC) -shared $(OBJS) -o $(TARGET)
$(OBJS):%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

########################################################################################
#make lib
########################################################################################

TARGETLIB := lib$(PROJECTNAME).a

slib:
	 $(AR) -cr $(TARGETLIB) SRC/aes.o     \
													SRC/arc4.o     \
													SRC/base64.o     \
													SRC/bignum.o     \
													SRC/certs.o     \
													SRC/debug.o     \
													SRC/des.o     \
													SRC/dhm.o     \
													SRC/havege.o     \
													SRC/md2.o     \
													SRC/md4.o     \
													SRC/md5.o     \
													SRC/net.o     \
													SRC/padlock.o     \
													SRC/rsa.o     \
													SRC/rsa2.o     \
													SRC/sha1.o     \
													SRC/sha2.o     \
													SRC/sha3.o     \
													SRC/ssl_cli.o     \
													SRC/ssl_srv.o     \
													SRC/timing.o     \
													SRC/x509parse.o

########################################################################################
#copy to the  release directory
########################################################################################

RELEASEDIR := $(SOLOICESKYDIR)/$(PROJECTNAME)/realease

release:
	 cp -rf $(TARGETLIB) $(RELEASEDIR)/libs/static
	 cp -rf SRC/*.h $(RELEASEDIR)/includes
	 cp -rf SRC/*.h $(INCDIR)
clean:
	rm $(OBJS) $(TARGET)
	rm -rf ./Release