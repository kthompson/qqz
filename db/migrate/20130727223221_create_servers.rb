class CreateServers < ActiveRecord::Migration
  def change
    create_table :servers do |t|
      t.string :name
      t.string :address
      t.string :version
      t.string :players
      t.integer :max_players

      t.timestamps
    end
  end
end
