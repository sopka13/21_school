<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'test' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', '123456' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '[y(U}bg`~b?)&1[5onJi|B%Ho c#fYw9EeMTwis{&}.5~S9d^J-eY&h9avXhp-/U' );
define( 'SECURE_AUTH_KEY',  'a{Hy7o*}^|<yuV,aq3z:PA Lp>++EG,d*co3+sA`HHu?neo(Uvr-7eT?U`n$o0CU' );
define( 'LOGGED_IN_KEY',    '-+?^csKP;#? 2q2ZLc2#fF1-:L4:#kY]EI%TAJuUYIa;q^v-IJXl;S|y/KHc@!tu' );
define( 'NONCE_KEY',        'E?CB;7!@$j>h>g@J;f{i`Z5!n#R[@JUR{rDW))1|f^Z<0<Y}X)/Cx[p2CCYh^nc@' );
define( 'AUTH_SALT',        'CujBHYmcyZ<rc^JQ@Be+RF.ruWBOj^AGc4+RHv(DTN}bw#: ~*}Xju+25t%n{#[y' );
define( 'SECURE_AUTH_SALT', 'jllXNEy?%)pw$2bZe+,mfAU_5.EM|}>)|Bb2HjneTRxQ+X,ju3>Zx*gC!yM0j:9j' );
define( 'LOGGED_IN_SALT',   'Cab(nq$cqGgW(q[%X[zj04gtl>x-y/(rKu:BT[#X7WsPOG*^HI)!hH7kWTgyOg|@' );
define( 'NONCE_SALT',       '.Z3.iWE|kJjf2st{WS8(+W8y5!+c{X)`M667>&4VAFO~bqi=+,.eqyKh*2p?.K[9' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';