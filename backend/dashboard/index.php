<?php
include "../core.php";
if (!isset($_SESSION['loggedin'])) {
    header("location:/dashboard/login.php");
}
include UI_HEADER_PATH;
include UI_NAVBAR_PATH;
?>

<div class="container px-24 mx-auto">
    <div class="grid gap-3 mt-12 grid-cols-6">
      
    </div>
</div>


<?php include UI_FOOTER_PATH ?>