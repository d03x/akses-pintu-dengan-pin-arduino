<nav class="w-full h-12 bg-white border-b shadow-sm">
    <div class="container px-24 mx-auto h-12  flex items-center justify-between">
        <h1 class="text-lg font-semibold text-blue-400">
            SMART KEY
        </h1>
        <div>
            <a class="text-sm font-semibold hover:bg-gray-100 p-2 text-gray-500 hover:text-green-500 transition-all" href="">Home</a>
            <?php if ($user['is_admin']): ?>
                <a class="text-sm font-semibold hover:bg-gray-100 p-2 text-gray-500 hover:text-green-500 transition-all" href="">Access Manager</a>
                <a class="text-sm font-semibold hover:bg-gray-100 p-2 text-gray-500 hover:text-green-500 transition-all" href="">Pin & RFID Manager</a>
            <?php else: ?>
                <a class="text-sm font-semibold hover:bg-gray-100 p-2 text-gray-500 hover:text-green-500 transition-all" href="">Pengaturan</a>

            <?php endif; ?>
            <a class="text-sm font-semibold hover:bg-gray-100 p-2 text-gray-500 hover:text-green-500 transition-all" href="">REMOTE ACCESS</a>
        </div>
    </div>
</nav>