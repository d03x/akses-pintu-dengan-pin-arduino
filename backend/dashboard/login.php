<?php
include "../core.php";
include "../core.php";
if (isset($_SESSION['loggedin'])) {
    header("location:/dashboard/index.php");
    die;
}

include FPATH . "dashboard" . DS . "ui" . DS . "head.php";

if (isset($_POST) && $_SERVER["REQUEST_METHOD"] === "POST") {
    $username = htmlentities(strip_tags($_POST['username'] ?? null));
    $password =  htmlentities(strip_tags($_POST['password'] ?? null));
    //sanitize and validation logic

    if ($username !== null && $password !== null) {
        $query = $koneksi->query("SELECT * FROM users WHERE username='$username' AND password='$password' ");
        if ($query->num_rows > 0) {
            $user = $query->fetch_assoc();
            $_SESSION['user'] = $user;
            $_SESSION['loggedin'] = true;
            $validUser = true;
            header('location:./index.php');
            exit;
        } else {
            $validUser = false;
        }
        if (!$validUser) {
            $_SESSION['error'] = "Email atau password salah";
            header('location:./login.php');
            die;
        }
    } else {
        $_SESSION['error'] = "Email atau password salah";
        header('location:./login.php');
        die;
    }
}
?>

<div class="flex justify-center items-center min-h-screen bg-gray-50">
    <div class="max-w-md w-full bg-white p-8 rounded-lg shadow-xl">
        <h2 class="text-3xl font-semibold text-center text-gray-700 mb-6">Login to Your Account</h2>

        <?php if (isset($_SESSION['error'])): ?>
            <div class="text-red-600 bg-red-200/40 border p-2 rounded border-red-600 text-sm text-center mb-4">
                <?php echo $_SESSION['error'];
                unset($_SESSION['error']); ?>
            </div>
        <?php endif; ?>

        <form action="" method="POST" class="space-y-6">
            <!-- Username -->
            <div>
                <label for="username" class="block text-sm font-medium text-gray-600">Username</label>
                <input id="username" type="text" class="mt-1 p-3 w-full rounded-lg border-2 border-gray-300 focus:ring-2 focus:ring-blue-500 outline-none" name="username" placeholder="Enter your username" required>
            </div>

            <!-- Password -->
            <div>
                <label for="password" class="block text-sm font-medium text-gray-600">Password</label>
                <input id="password" type="password" class="mt-1 p-3 w-full rounded-lg border-2 border-gray-300 focus:ring-2 focus:ring-blue-500 outline-none" name="password" placeholder="Enter your password" required>
            </div>

            <!-- Submit Button -->
            <div>
                <button type="submit" class="w-full py-3 bg-blue-600 text-white font-semibold rounded-lg hover:bg-blue-700 transition duration-300">Login</button>
            </div>
        </form>

    </div>
</div>

<?php include FPATH . "dashboard" . DS . "ui" . DS . "footer.php"; ?>