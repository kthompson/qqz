json.array!(@servers) do |server|
  json.extract! server, :name, :address, :version, :players, :max_players
  json.url server_url(server, format: :json)
end
