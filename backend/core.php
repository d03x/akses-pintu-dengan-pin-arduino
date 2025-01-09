<?php
session_start();
define("DS", DIRECTORY_SEPARATOR);
define("FPATH", __DIR__ . DIRECTORY_SEPARATOR);
define("UI_HEADER_PATH", FPATH . "dashboard" . DS . "ui" . DS . "head.php");
define("UI_FOOTER_PATH", FPATH . "dashboard" . DS . "ui" . DS . "footer.php");
define("UI_NAVBAR_PATH", FPATH . "dashboard" . DS . "ui" . DS . "navbar.php");

try {
    $koneksi = new mysqli("localhost", "root", "root", "pintu");
} catch (\Throwable $th) {
    die($th->getMessage());
}
