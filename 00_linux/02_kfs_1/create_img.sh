#!/bin/bash

SUCCESS=0
ROOT_UID=0
MOUNT_POINT=/mnt/kfs_1
KERNEL_NAME_IN=kernel
KERNEL_NAME_OUT=vmlinuz-my

if [ $UID != $ROOT_UID ]
then
	echo "This script for ROOT only"
	exit 1
fi

echo "Check ROOT user: $?"

grub_version=$(grub-install --version)
# echo $grub_version

if [ "$?" != $SUCCESS ]
then
	echo "GRUB version not supported. I need GRUB, not GRUB2 and other."
	exit 1
else
	echo "GRUB version: " $grub_version
	echo "It's fine."
fi

echo "Check GRUB version: $?"

# Create kernel
# nasm -f elf32 kernel.asm -o kasm.o
# gcc -m32 -c kernel.c -o kc.o
# ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o

# Create img
dd if=/dev/zero of=out.img seek=8MB count=1K bs=1

echo "Create img: $?"

# Image layout
parted --script out.img \
			mklabel msdos \
			mkpart primary ext2 32k 100% \
			toggle 1 boot

echo "Parted my img: $?"

# Create block device from image
free_loop_0=$(losetup -f)
free_loop_0_p="/dev/mapper/${free_loop_0:5}p1"
echo "Get free loops: $?; free_loop_0 = $free_loop_0; free_loop_0_p = $free_loop_0_p"
losetup $free_loop_0 out.img
echo "losetup_1: $?"
kpartx -v -a $free_loop_0
echo "kpartx: $?"
free_loop_1=$(losetup -f)
echo "Get 1 more free loop: $?; free_loop_1 = $free_loop_1"
losetup $free_loop_1 $free_loop_0_p
echo "losetup_2: $?"

echo "Premount manipulation: $?"

# Create filesystem in image
mke2fs $free_loop_1

echo "Install fs: $?"

# Mount image
mkdir $MOUNT_POINT
mount $free_loop_1 $MOUNT_POINT

echo "Mount disk: $?"

# Create folders for grub
grub_folder="$MOUNT_POINT/boot/grub"
mkdir -p $grub_folder

echo "Mkdir for new partition: $?"

# Install grub
boot_folder="$MOUNT_POINT/boot/"
grub-install --boot-directory=$boot_folder \
				--modules="ext2 part_msdos" \
				--target=i386-pc \
				$free_loop_0

echo "GRUB install: $?"

# Copy kernel and grub.cfg
cp grub.cfg $grub_folder
temp="$boot_folder$KERNEL_NAME_OUT"
cp $KERNEL_NAME_IN $temp

echo "Copy files: $?"

# Clear space
umount $MOUNT_POINT
kpartx -d $free_loop_1
kpartx -d $free_loop_0
losetup -d $free_loop_0

echo "Clear mountpoints: $?"