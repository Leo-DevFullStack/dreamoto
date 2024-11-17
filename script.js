const SHEETDB_URL = "https://sheetdb.io/api/v1/85elowbdmjk2x";

const form = document.getElementById("formMoto");
const tabelaMotos = document.getElementById("tabelaMotos").querySelector("tbody");

document.addEventListener("DOMContentLoaded", () => {
    carregarDoSheetDB();
});

form.addEventListener("submit", (e) => {
    e.preventDefault();
    const moto = {
        id: document.getElementById("id").value,
        marca: document.getElementById("marca").value,
        tipo: document.getElementById("tipo").value,
        modelo: document.getElementById("modelo").value,
        ano: document.getElementById("ano").value,
        cor: document.getElementById("cor").value,
        preco: parseFloat(document.getElementById("preco").value),
    };

    cadastrarMoto(moto);
    form.reset();
});

function carregarDoSheetDB() {
    fetch(SHEETDB_URL)
        .then((response) => response.json())
        .then((dados) => {
            tabelaMotos.innerHTML = "";

            dados.forEach((moto) => {
                const row = document.createElement("tr");
                row.innerHTML = `
                    <td>${moto.id}</td>
                    <td>${moto.marca}</td>
                    <td>${moto.tipo}</td>
                    <td>${moto.modelo}</td>
                    <td>${moto.ano}</td>
                    <td>${moto.cor}</td>
                    <td>R$ ${parseFloat(moto.preco).toFixed(2)}</td>
                    <td>
                        <button onclick="planejarCompra('${moto.id}')">Planejar</button>
                    </td>
                `;
                tabelaMotos.appendChild(row);
            });
        })
        .catch((error) => {
            console.error("Erro ao carregar dados do SheetDB:", error);
        });
}

function cadastrarMoto(moto) {
    fetch(SHEETDB_URL, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ data: [moto] }),
    })
        .then((response) => {
            if (response.ok) {
                alert("Moto cadastrada com sucesso!");
                carregarDoSheetDB();
            } else {
                alert("Erro ao cadastrar moto no SheetDB.");
            }
        })
        .catch((error) => {
            console.error("Erro de conexão com o SheetDB:", error);
        });
}

function planejarCompra(id) {
    fetch(SHEETDB_URL)
        .then((response) => response.json())
        .then((dados) => {
            const moto = dados.find((m) => m.id === id);
            if (!moto) {
                alert("Moto não encontrada!");
                return;
            }

            const economiaMensal = parseFloat(prompt("Quanto você pode economizar por mês?"));
            if (isNaN(economiaMensal) || economiaMensal <= 0) {
                alert("Valor inválido!");
                return;
            }

            const meses = Math.ceil(moto.preco / economiaMensal);
            alert(`Você precisará de ${meses} meses para comprar a ${moto.marca} ${moto.modelo} guardando R$ ${economiaMensal.toFixed(2)} por mês.`);
        });
}