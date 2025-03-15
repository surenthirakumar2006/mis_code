FROM alpine:latest

RUN apk add --no-cache socat

WORKDIR /app

COPY mystery .
COPY flag .

EXPOSE 1338

CMD ["socat", "-T60", "TCP-LISTEN:1338,fork,reuseaddr", "EXEC:./mystery"]