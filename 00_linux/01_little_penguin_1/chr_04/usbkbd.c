#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/kref.h>
#include <linux/uaccess.h>
#include <linux/usb.h>
#include <linux/hid.h>

/* Define these values to match your devices */
#define USB_MY_MOUSE_VENDOR_ID	0x046d
#define USB_MY_MOUSE_PRODUCT_ID	0xc077

// struct usbkbd_controller {
// 	struct usb_device *udev;
// 	struct usb_interface *interface;
// 	unsigned char minor;

// 	char *int_in_buffer;
// 	struct usb_endpoint_descriptor *endpoint;
// 	struct urb *int_in_urb;
// };

/* table of devices that work with this driver */
static const struct hid_device_id support_dev_table[] = {
	{ HID_USB_DEVICE(USB_MY_MOUSE_VENDOR_ID,
					USB_MY_MOUSE_PRODUCT_ID) },
	{ }					/* Terminating entry */
};
MODULE_DEVICE_TABLE(hid, support_dev_table);

static int skel_probe(struct hid_device *device,
			  const struct hid_device_id *id)
{
	int minor = device->product;
	pr_info("USB device id #%d now connected: idVendor = %d; idProduct = %d",
			minor, id->vendor, id->product);

	return 0;
}

static void skel_disconnect(struct hid_device *device)
{
	int minor = device->product;
	pr_info("USB device #%d now disconnected", minor);
}

static struct hid_driver skel_driver = {
	.name =		"usbkbd",
	.probe =	skel_probe,
	.remove =	skel_disconnect,
	.id_table =	support_dev_table,
	// .supports_autosuspend = 1
};

static int __init usb_skel_init(void)
{
	int result;

	pr_info("USBKBD register");

	/* register this driver with the USB subsystem */
	result = hid_register_driver(&skel_driver);
	// if (result < 0) {
		pr_warn("usb_register failed for the "__FILE__ "driver."
			"Error number %d", result);
	// 	return -1;
	// }

	return 0;
}

static void __exit usb_skel_exit(void)
{
	pr_info("USBKBD deregister");

	/* deregister this driver with the USB subsystem */
	hid_unregister_driver(&skel_driver);
}

module_init(usb_skel_init);
module_exit(usb_skel_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sergey Seliverstov eyohn <sopka13@mail.ru>");
MODULE_DESCRIPTION("Tested module");
