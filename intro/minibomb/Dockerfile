FROM pwn.red/jail

COPY --from=debian:bullseye-slim / /srv
COPY minibomb /srv/app/run
COPY flag.txt /srv/app/flag.txt
RUN chmod 755 /srv/app/run
