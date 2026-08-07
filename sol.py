import requests
from bs4 import BeautifulSoup

def decode_secret_message(url: str) -> None:
    response = requests.get(url)
    response.raise_for_status()
    soup = BeautifulSoup(response.text, "html.parser")
    table = soup.find("table")

    points = []
    max_x = 0
    max_y = 0

    rows = table.find_all("tr")[1:]  # Skip header row
    for row in rows:
        cols = [cell.get_text(strip=True) for cell in row.find_all("td")]
        if len(cols) != 3:
            continue
        x = int(cols[0])
        char = cols[1]
        y = int(cols[2])
        points.append((x, y, char))
        max_x = max(max_x, x)
        max_y = max(max_y, y)

    grid = [[" " for _ in range(max_x + 1)] for _ in range(max_y + 1)]
    for x, y, char in points:
        grid[y][x] = char

    # Print from y=0 (top) to max_y (bottom) so the text is upright
    for y in range(max_y + 1):
        print("".join(grid[y]))


if __name__ == "__main__":
    decode_secret_message("https://docs.google.com/document/d/e/2PACX-1vSvM5gDlNvt7npYHhp_XfsJvuntUhq184By5xO_pA4b_gCWeXb6dM6ZxwN8rE6S4ghUsCj2VKR21oEP/pub")