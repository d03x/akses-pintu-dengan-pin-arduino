import express from "express";
import { Server } from "ws";

const app = express();
const PORT = 3000; // Port yang digunakan
const HOST = "192.168.43.50"; // Ganti dengan IP Anda

// HTTP server dari Express
const server = app.listen(PORT, HOST, () => {
  console.log(`Server berjalan di http://${HOST}:${PORT}`);
});

// WebSocket server
const wss = new Server({ server });

// Tangani koneksi WebSocket
wss.on("connection", (ws) => {
  console.log("Klien terhubung");

  // Kirim pesan ke klien saat koneksi berhasil
  ws.send("Selamat datang di WebSocket server TypeScript!");

  // Tangani pesan yang diterima dari klien
  ws.on("message", (message) => {
    console.log(`Pesan diterima: ${message}`);
    ws.send(`Echo: ${message}`);
  });

  // Tangani klien yang terputus
  ws.on("close", () => {
    console.log("Klien terputus");
  });
});

// Rute default untuk memverifikasi server
app.get("/", (req, res) => {
  res.send("WebSocket server berjalan dengan TypeScript!");
});
