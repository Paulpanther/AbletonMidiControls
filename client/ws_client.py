import asyncio
import json
import sys

import websockets

from client.midi import Midi


async def run_client(ip):
    midi = Midi()

    async with websockets.connect(f"ws://{ip}/ws") as websocket:
        async for message in websocket:
            print(message)
            data = json.loads(message)
            if data["type"] == "event":
                event = data["event"]
                midi.send(int(event["status"]), int(event["key"]), int(event["value"]), int(event["channel"]))

if __name__ == '__main__':
    ip = sys.argv[1]
    asyncio.run(run_client(ip))
